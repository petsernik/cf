# cf

Реализация известных алгоритмов и структур для последующего использования в раундах [codeforces.com](codeforces.com).
В vs code на слабых машинах snippets подгружаются долго, так что иногда использую shortcuts, задаваемые в keybindigs.json:

```java
// Поместите настраиваемые сочетания клавиш в этот файл, чтобы переопределить сочетания клавиш по умолчанию.
[
    {
        "key": "alt+f",
        "command": "editor.action.insertSnippet",
        "args": {
            "snippet": "for (ll ${1:i} = ${2:0}; $1 < ${3:n}; ++$1) {\n    $0\n}"
        }
    },
    {
        "key": "alt+l",
        "command": "editor.action.insertSnippet",
        "args": {
            "snippet": "ll ${1:n};\ncin >> $1;\n$0"
        }
    },
    {
        "key": "alt+p",
        "command": "editor.action.insertSnippet",
        "args": {
            "snippet": "print($1);\n$0"
        }
    },
    {
        "key": "alt+d",
        "command": "editor.action.insertSnippet",
        "args": {
            "snippet": "for (ll ${3:i} = ${2:n - 1}; $3 >= ${4:0}; --$3) {\n    $0\n}"
        }
    },
    {
        "key": "alt+v",
        "command": "editor.action.insertSnippet",
        "args": {
            "snippet": "vec<${3:ll}> ${1:a}(${2:n});\n$0"
        }
    },
    {
        "key": "alt+s",
        "command": "editor.action.insertSnippet",
        "args": {
            "snippet": "string ${1:s};\ncin >> $1;\n$0"
        }
    },
    {
        "key": "ctrl+alt+c",
        "command": "editor.action.insertSnippet",
        "args": {
            "snippet": "cin >> $1;\n$0"
        }
    },
    {
        "key": "alt+i",
        "command": "editor.action.formatDocument"
    },
]
```
