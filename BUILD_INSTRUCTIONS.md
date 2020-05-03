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

Now to execute it you do (still in root directory of repo):

```
docker run -v $(pwd)/fengwang-matrix/program_io:/program_io fengwang-matrix-svd
```

Feed in the input matrix `A` by writing a serialized numpy array into `./fengwang-matrix/program_io/input.npy`. The resulting matrices from running SVD are stored as grayscale bitmaps (library does not currently export npy files) in the same `program_io` directory.


## Notes

Docker will run in a VM so ideally when we benchmark we will only want to keep
track of things that don't do any IO interaction. Loading and saving .bmp images
for example will be a lot slower but SVD should run normally (assuming your
cpu has virtualization enabled). Or just run on linux.
