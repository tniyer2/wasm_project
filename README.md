
Requirements
==============

You need to have EMScripten installed.
You need to have the latest version of Python.

How to Build
==============

Run the Command:
emcc hello.c -s WASM=1 -s EXPORTED_RUNTIME_METHODS='["cwrap"]' -o hello.html

How to Run
==============

Start a simple Python server.
Run the Command:
python3 -m http.server

On the website click on example.html
