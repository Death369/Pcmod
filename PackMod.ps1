$ErrorActionPreference = "Stop"

# --- Paths ---
$DayZToolsBin = "C:\Program Files (x86)\Steam\steamapps\common\DayZ Tools\Bin"
$AddonBuilder = "$DayZToolsBin\AddonBuilder\AddonBuilder.exe"
$DSCreateKey = "$DayZToolsBin\DsUtils\DSCreateKey.exe"
$DSSignFile = "$DayZToolsBin\DsUtils\DSSignFile.exe"

$SourceDir = "C:\Program Files (x86)\Steam\steamapps\common\Mods\ORIGINAL\PCmod"
$KeyName = "PCmod"

# Output Locations
$Dest1_Root = "C:\Program Files (x86)\Steam\steamapps\common\Mods\BACKUP\PCmod"
$Dest1_Key = "$Dest1_Root\Keys"

$Dest2_Root = "C:\Users\Administrator\Pictures\DayZ_Mods\Packed\PCmod"
$Dest2_Key = "C:\Users\Administrator\Pictures\DayZ_Mods\Keys"

# Temporary Working Directory for Keys
$TempKeyDir = "C:\Users\Administrator\Pictures\DayZ_Mods\Keys"
if (!(Test-Path $TempKeyDir)) { New-Item -ItemType Directory -Path $TempKeyDir }

# --- 1. Key Generation ---
Set-Location $TempKeyDir
$PrivateKeyPath = Join-Path $TempKeyDir "$KeyName.biprivatekey"
$PublicKeyPath = Join-Path $TempKeyDir "$KeyName.bikey"

if (!(Test-Path $PrivateKeyPath)) {
    Write-Host "Generating new key pair: $KeyName" -ForegroundColor Cyan
    & $DSCreateKey $KeyName
} else {
    Write-Host "Using existing key: $KeyName" -ForegroundColor Yellow
}

# --- 2. Packing and Signing ---
$Addons = @("PCclient", "PCserver")

foreach ($Addon in $Addons) {
    $AddonSource = Join-Path $SourceDir $Addon
    # Target folder: <Root>\@Addon\Addons
    $ModRoot = Join-Path $Dest2_Root "@$Addon"
    $AddonDest = Join-Path $ModRoot "Addons"
    $AddonKeys = Join-Path $ModRoot "Keys"
    
    if (!(Test-Path $AddonDest)) { New-Item -ItemType Directory -Path $AddonDest -Force }
    if (!(Test-Path $AddonKeys)) { New-Item -ItemType Directory -Path $AddonKeys -Force }
    
    Write-Host "Packing and Signing $Addon -> $AddonDest" -ForegroundColor Cyan
    
    $Params = @(
        $AddonSource,
        $AddonDest,
        "-prefix=$Addon",
        "-sign=$PrivateKeyPath",
        "-clear",
        "-packonly"
    )
    
    & $AddonBuilder @Params
    
    if ($LASTEXITCODE -ne 0) {
        Write-Error "Failed to pack/sign $Addon"
    }

    # Copy Public Key into the individual @Mod/Keys folder
    Copy-Item $PublicKeyPath $AddonKeys -Force
}

# --- 3. Distribution to BACKUP ---
Write-Host "Distributing files to BACKUP location..." -ForegroundColor Cyan

# Ensure Backup Root Key folder exists (for general keys folder)
if (!(Test-Path $Dest1_Key)) { New-Item -ItemType Directory -Path $Dest1_Key -Force }

foreach ($Addon in $Addons) {
    $SourceModRoot = Join-Path $Dest2_Root "@$Addon"
    $BackupModRoot = Join-Path $Dest1_Root "@$Addon"
    
    # Create structure in Backup
    $BackupAddons = Join-Path $BackupModRoot "Addons"
    $BackupKeys = Join-Path $BackupModRoot "Keys"
    
    if (!(Test-Path $BackupAddons)) { New-Item -ItemType Directory -Path $BackupAddons -Force }
    if (!(Test-Path $BackupKeys)) { New-Item -ItemType Directory -Path $BackupKeys -Force }
    
    # Copy PBO and Signature to Backup
    Copy-Item (Join-Path $SourceModRoot "Addons\$Addon.pbo") $BackupAddons -Force
    Copy-Item (Join-Path $SourceModRoot "Addons\$Addon.pbo.$KeyName.bisign") $BackupAddons -Force
    
    # Copy Key to Backup @Mod/Keys folder
    Copy-Item $PublicKeyPath $BackupKeys -Force
}

# Copy Public Key to Backup
Copy-Item $PublicKeyPath $Dest1_Key -Force

Write-Host "Mod packed and signed successfully!" -ForegroundColor Green
Write-Host "Deployment 1 (Backup): $Dest1_Root"
Write-Host "Deployment 2 (Packed): $Dest2_Root"
