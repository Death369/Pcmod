# PowerShell Script to Pack, Sign, and Deploy DayZ Mod
$ErrorActionPreference = "Stop"

# --- Paths ---
$DayZToolsBin = "C:\Program Files (x86)\Steam\steamapps\common\DayZ Tools\Bin"
$AddonBuilder = "$DayZToolsBin\AddonBuilder\AddonBuilder.exe"
$DSCreateKey = "$DayZToolsBin\DsUtils\DSCreateKey.exe"
$ServerDir = "C:\Program Files (x86)\Steam\steamapps\common\DayZServer"

$SourceDir = "C:\Program Files (x86)\Steam\steamapps\common\Mods\ORIGINAL\PCmod"
$KeyName = "PCmod"

# Output Locations
$Dest1_Root = "C:\Program Files (x86)\Steam\steamapps\common\Mods\BACKUP\PCmod"
$Dest2_Root = "C:\Users\Administrator\Pictures\DayZ_Mods\Packed\PCmod"
$TempKeyDir = "C:\Users\Administrator\Pictures\DayZ_Mods\Keys"

# --- 1. Key Verification ---
$PrivateKeyPath = Join-Path $TempKeyDir "$KeyName.biprivatekey"
$PublicKeyPath = Join-Path $TempKeyDir "$KeyName.bikey"

if (!(Test-Path $PrivateKeyPath)) {
    Write-Host "Generating new key pair..." -ForegroundColor Cyan
    if (!(Test-Path $TempKeyDir)) { New-Item -ItemType Directory -Path $TempKeyDir }
    Set-Location $TempKeyDir
    & $DSCreateKey $KeyName
}

# --- 2. Packing and Signing ---
$Addons = @("PCclient", "PCserver")

foreach ($Addon in $Addons) {
    $AddonSource = Join-Path $SourceDir $Addon
    $ModRoot = Join-Path $Dest2_Root "@$Addon"
    $AddonDest = Join-Path $ModRoot "Addons"
    $AddonKeys = Join-Path $ModRoot "Keys"
    
    if (!(Test-Path $AddonDest)) { New-Item -ItemType Directory -Path $AddonDest -Force }
    if (!(Test-Path $AddonKeys)) { New-Item -ItemType Directory -Path $AddonKeys -Force }
    
    Write-Host "Packing $Addon..." -ForegroundColor Cyan
    & $AddonBuilder $AddonSource $AddonDest "-prefix=$Addon" "-sign=$PrivateKeyPath" "-clear" "-packonly"
    
    Copy-Item $PublicKeyPath $AddonKeys -Force
}

# --- 3. Distribution to BACKUP ---
Write-Host "Syncing to BACKUP..." -ForegroundColor Cyan
if (!(Test-Path $Dest1_Root)) { New-Item -ItemType Directory -Path $Dest1_Root -Force }
Copy-Item $Dest2_Root\* $Dest1_Root -Recurse -Force

# --- 4. Distribution to SERVER ---
Write-Host "Deploying to SERVER..." -ForegroundColor Cyan
foreach ($Addon in $Addons) {
    $ServerModPath = Join-Path $ServerDir "Mods\@$Addon"
    if (Test-Path $ServerModPath) { Remove-Item $ServerModPath -Recurse -Force }
    New-Item -ItemType Directory -Path $ServerModPath -Force
    Copy-Item "$Dest2_Root\@$Addon\*" $ServerModPath -Recurse -Force
}

# Copy key to server keys folder
$ServerKeys = Join-Path $ServerDir "keys"
if (!(Test-Path $ServerKeys)) { New-Item -ItemType Directory -Path $ServerKeys -Force }
Copy-Item $PublicKeyPath $ServerKeys -Force

Write-Host "Build and Deployment Successful!" -ForegroundColor Green
