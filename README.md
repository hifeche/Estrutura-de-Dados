# Estruturas de dados

<pre>
# Compilar
gcc -g hello.c -o hello.app
# Executar
./hello.app
</pre>

## Compile and run c (vscode)

### Option 1: Code Runner Extension

Let's you use `Ctrl + Alt + N` to compile and run whatever file is currently open.

Setup Steps:

- Open Extensions (`Ctrl + Shift + X`) in VS Code and search for Code Runner - *formulahendry.code-runner* -, then click Install.

- Open Settings (`Ctrl + ,`), search for executorMap, and click Edit in settings.json.
- Add or update the "c" line in code-runner.executorMap to:

```json
"code-runner.executorMap": {
  "c": "cd $dir && gcc -g $fileName -o $fileNameWithoutExt.app && ./$fileNameWithoutExt.app"
},
"code-runner.runInTerminal": true
```

Usage: Press `Ctrl + Alt + N` 


### Option 2: Native VS Code Task

Only native, build-and-run task bound to a single shortcut.

Setup Steps:

In VS Code, press `Ctrl + Shift + P` and type **Tasks: Configure Task**.

Select Create/Open **tasks.json** file and replace the contents with:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Compile and Run C",
      "type": "shell",
      "command": "gcc -g ${file} -o ${fileDirname}/${fileBasenameNoExtension}.app && ${fileDirname}/${fileBasenameNoExtension}.app",
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "presentation": {
        "reveal": "always",
        "panel": "dedicated"
      }
    }
  ]
}
```

Usage:

Press `Ctrl + Shift + B` while viewing any C file to compile and execute it immediately in the integrated terminal.
