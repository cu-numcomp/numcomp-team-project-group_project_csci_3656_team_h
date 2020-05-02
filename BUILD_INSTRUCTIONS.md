# Building & running the C++ matrix code

Since [fengwang/matrix](https://github.com/fengwang/matrix) uses c++20, which is
not fully released yet we need to make sure we can build it. We were completely
unable to compile it on macOS, so we use Docker to build and run it.

## Building

**You need to install [Docker](https://www.docker.com/get-started).**

After Docker is started on your machine, run the following in the root directory
of this git repo.

```
docker build -t fengwang-matrix-svd .
```

## Running

Now to execute it you do:

```
docker run -v $(pwd)/fengwang-matrix/input.txt:/input.txt fengwang-matrix-svd
```

## Notes

Docker will run in a VM so ideally when we benchmark we will only want to keep
track of things that don't do any IO interaction. Loading and saving .bmp images
for example will be a lot slower but SVD should run normally (assuming your
cpu has virtualization enabled). Or just run on linux.
