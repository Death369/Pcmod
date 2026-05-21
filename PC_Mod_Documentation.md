# DayZ PC Mod - Technical Documentation (v2026)

This document provides a comprehensive technical breakdown of the "PC Mod" for DayZ, covering both client-side assets/logic and server-side systems. It is designed for AI systems and developers to understand the architecture, data flow, and item relationships.

---

## 1. Core Concept
The mod introduces a high-tier loot acquisition loop centered around **Electronic Warfare and Decryption**. Players salvage PC components, assemble a functional computer workstation, and use it to decrypt stolen hard drives containing coordinates to hidden underground stashes.

---

## 2. Mod Structure Overview

### A. Client (`PCclient`)
- **Assets:** 3D models (`.p3d`) for all components, textures (`.paa`), and sound sets (`.ogg`).
- **GUI:** Dynamic 3D UI implemented via `SetObjectTexture` on the system block monitor.
- **Actions:** 
    - `ActionCheckGG_compukter`: Salvaging parts with a screwdriver.
    - `ActionActivateSysblock`: Initializing the hardware.
    - `ActionDigOutStash`: Digging up rewards with a shovel.

### B. Server (`PCserver`)
- **Config:** JSON-based system (`config.json`) stored in the server profile.
- **Helpers:**
    - `PCLootHelper`: Manages spawn chances, damage calculations, and loot table selection.
    - `PCSpawnHelper`: Handles the physical spawning of stashes in the world.
- **Synchronization:** Uses `RegisterNetSyncVariable` to replicate decryption progress and stash coordinates to the client.

---

## 3. Item Hierarchy & Slot System

### GG_SYSBLOCK (The Mainframe)
The central entity where all components are installed.
- **Required Slots (For Operation):**
  - `mboard`: Motherboard
  - `cpu`: Processor
  - `ram`: Memory
  - `hdd_os`: Operating System Drive (Determines Decryption Speed)
- **Peripheral Slots (For Interaction/Display):**
  - `monitor`: Required for visual feedback of progress/coordinates.
  - `mouse` / `keyboard`: Required for the system to be "complete" and allow hacking.
- **Power:** Requires connection to a power source (EnergyManager, `plugType=2`).

### Components
1. **Drives (HDDs):**
   - **OS Drives:** `GG_HDD_OS` (Basic), `GG_HDD_OS_Police` (1.5x speed), `GG_HDD_OS_Army` (2.0x speed).
   - **Encrypted Drives:** `GG_HDD_City`, `GG_HDD_Police`, `GG_HDD_Army`, `GG_HDD_Quest`, `GG_HDD_Legacy`.
2. **Hardware:** `GG_MBOARD`, `GG_CPU`, `GG_RAM`, `GG_MONITOR`, `GG_MOUSE`, `GG_KEYBOARD`.

---

## 4. The Decryption Lifecycle (Logical Flow)

### Phase 1: Salvaging
Players find static world objects (`GG_compukter` variants). Using a **Screwdriver**, they perform a continuous action to salvage parts. The server rolls chances (defined in `config.json`) to drop PC components.

### Phase 2: Assembly & Initialization
1. Player finds/crafts a `GG_SYSBLOCK`.
2. Connects it to power.
3. Installs the required hardware + one OS Drive + one Encrypted Drive.
4. **POST Check:** On startup, the PC checks for core hardware. If missing, it plays an Error Beep and shuts down.

### Phase 3: Hacking (The Timer Loop)
When the PC is "Working" (Power + On + Core Hardware):
1. **Server Update Loop (Every 60s):**
   - **Progress Addition:** Adds % to the HDD based on: `(100 / HackTime) * OSSpeed`.
   - **Hardware Degradation:** All components (including the Case) take health damage every tick. Better OS/Harder Drives increase this damage.
   - **Ruin Logic:** If the Motherboard, CPU, or OS drive reaches 0% health, the system performs an emergency shutdown.

### Phase 4: Stash Spawning & Discovery
1. **Success:** Once progress reaches 100%, the server spawns an invisible `UndergroundStash` object at a coordinate assigned to the HDD when it was first created.
2. **Feedback:** The Monitor texture updates from "Progress %" to "X/Z Coordinates".
3. **Recovery:** The player travels to the location and uses a **Shovel**. The stash (dirt pile) is dug up, revealing the loot.

---

## 5. Server Configuration (`config.json`)

The system is fully customizable via `$profile:PCmod\config.json`.

| Parameter | Description |
| :--- | :--- |
| `GlobalDamageMultiplier` | Scales how fast hardware breaks during hacking. |
| `HackTime` | Base seconds required to decrypt a drive (per tier). |
| `Chance<Part>` | Percentage chance to drop a specific part from a workstation. |
| `CoordinatesData` | List of possible X/Z locations for stashes. |
| `LootSets<Tier>` | Array of possible loot items (classnames, health, quantity). |

---

## 6. Technical Implementation Details

### Texture-Based UI
The system block uses 11 texture slots:
- `Slot 0`: Main background (OS Logo or Coordinate Screen).
- `Slot 1-5`: X-coordinate digits or Progress digits.
- `Slot 6-10`: Z-coordinate digits.
- Textures are pulled from `PCclient\HDD\cifra\` (0-9) and `PCclient\HDD\letter1\` (special chars).

### Networking (Client-Server Communication)
- **HDD State:** `m_DecryptionProgress` and `m_StashPos` are synced from server to client.
- **System State:** `OnWorkStart` and `OnWorkStop` trigger the server-side hacking timer and client-side sound/light effects.

### Security & Anti-Cheese
- HDDs are ruined upon successful decryption to prevent infinite loot.
- Stashes are only interactable (diggable) if the hacking process was legitimately completed.
- Salvaging workstations consumes tool health (Screwdriver/Shovel).

---

## 7. AI Extension Guide
To add a new tier of drive (e.g., "Special Event Drive"):
1. **Config:** Define a new class in `config.cpp` inheriting from `GG_HDD`.
2. **Server Logic:** Add the classname to the `PCLootHelper` switch cases for tier detection.
3. **JSON:** Add a new `LootSet` and `DriveSettings` entry in `config.json`.
4. **UI:** No changes needed; the system automatically displays progress/coords based on the `GG_HDD` base logic.
