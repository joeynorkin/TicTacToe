# Tic-tac-toe

A command-line game of Tic-tac-toe!

## How do I build?

You need [CMake](https://cmake.org/) version 3.13.4 or later to build. Follow
the link or if you're on macOS, run `brew install cmake` (You do have
[Homebrew](https://brew.sh/), right?).

Create a build directory anywhere you want and run
`cmake <path-to-tic-tac-toe-root>`. Then run `make`. This will generate an
executable called **tictactoe**.

For example:
```bash
# Assuming we're in the root director of TicTacToe
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./tictactoe # to run the game
```
