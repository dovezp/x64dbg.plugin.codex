# 🧩📚 Codex - Simplifying Python-based Solutions for x64dbg
Welcome to Codex, your go-to solution for managing and executing Python-based scripts within x64dbg! Codex is an innovative plugin designed to streamline your workflow in x64dbg. It offers a seamless way to store and execute Python-based solutions directly from the disassembler context menu and the x64dbg top plugins menu.

### Key Features
* Effortless Integration: Codex seamlessly integrates with x64dbg, offering a user-friendly interface to manage and execute Python scripts.
* Quick Access Execution: Execute Python-based solutions with just a few clicks, enhancing your debugging efficiency.
* Flexible Configuration: Customize menu items, folder structures, and script names to match your workflow.

### Feature Demo
See the Codex Plugin in action:

https://github.com/dovezp/x64dbg.plugin.codex/assets/89095890/ae2892c7-ec0e-40c7-b894-08ae97943743

### Requirements
To harness the power of Codex, ensure you have the following components:

* Windows Operating System
    * [Visual C++ Redistributable for Visual Studio 2015](https://www.microsoft.com/en-US/download/details.aspx?id=48145)
    * [Microsoft .NET Framework 4](https://www.microsoft.com/en-US/download/details.aspx?id=17718)
* x64dbgpy Plugin
    * Python 2.7 (PyQt4, PyQt5, and PySide)

### Getting Started
1. Download the latest [release](https://github.com/dovezp/x64dbg.plugin.codex/releases) build of Codex.
2. Extract the release folder to x64dbg's root directory.
3. Install x64dbgpy and ensure PyQt4, PyQt5, and PySide are located within `"...\plugins\x64dbgpy\".`

### Configuration and Usage
* Edit the settings in `"...\plugins\codex\settings.json"` to customize menu items and organize scripts.
* You can create nested folders, making organization a breeze.
* Simplify script names for a clearer understanding of their purpose.
* Each script can import and use additional files, enhancing versatility.

### Examples
To see Codex in action, check out my example script:

Oreans - OEP Finder (Universal)
Here's a glimpse of the default settings.json structure:

```json
{
    "settings": {
        "scripts": {
            "menu": [
                {"folder": "Oreans", "name": "OEP Finder (Universal)", "file": "oreans_oep_finder_uni.py"}
            ],
            "disassembly": [
                {"folder": "Deobfuscate", "name": "PUSH/POP -> MOV", "file": "push_pop.py"}
            ]
        }
    }
}
```

### License
This project operates under the [Apache License 2.0 (Apache-2.0)](https://tldrlegal.com/license/apache-license-2.0-(apache-2.0)). Please refer to the [LICENSE.md](./LICENSE.md) file for detailed information.

### Your Feedback Counts

Your insights and feedback, whether positive or constructive, are immensely valuable. Your contributions guide the refinement of the Codex Plugin for future iterations.

Share your thoughts by opening an issue in the [repository's issue section](https://github.com/dovezp/x64dbg.plugin.codex/issues). Be sure to provide context and links when sharing your feedback.

Thank you for being an essential part of the Codex Plugin's growth journey.

<p align="center">
  <p align="center">
    <a href="https://hits.seeyoufarm.com/api/count/graph/dailyhits.svg?url=https://github.com/dovezp/x64dbg.plugin.codex">
      <img src="https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fdovezp%2Fx64dbg.plugin.codex&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=true" alt="repository hits">
    </a>
    <a href="https://github.com/dovezp/x64dbg.plugin.codex/releases">
      <img src="https://img.shields.io/github/downloads/dovezp/x64dbg.plugin.codex/total?style=flat-square" alt="downloads"/>
    </a>
    <a href="https://github.com/dovezp/x64dbg.plugin.codex/graphs/contributors">
      <img src="https://img.shields.io/github/contributors/dovezp/x64dbg.plugin.codex?style=flat-square" alt="contributors"/>
    </a>
    <a href="https://github.com/dovezp/x64dbg.plugin.codex/watchers">
      <img src="https://img.shields.io/github/watchers/dovezp/x64dbg.plugin.codex?style=flat-square" alt="watchers"/>
    </a>
    <a href="https://github.com/dovezp/x64dbg.plugin.codex/stargazers">
      <img src="https://img.shields.io/github/stars/dovezp/x64dbg.plugin.codex?style=flat-square" alt="stars"/>
    </a>
    <a href="https://github.com/dovezp/x64dbg.plugin.codex/network/members">
      <img src="https://img.shields.io/github/forks/dovezp/x64dbg.plugin.codex?style=flat-square" alt="forks"/>
    </a>
  </p>
</p>

<p align="center">
  <a href="https://github.com/dovezp">
    <img width="64" heigth="64" src="https://avatars.githubusercontent.com/u/89095890" alt="dovezp"/>
  </a>
</p>
