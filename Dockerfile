FROM gcc:latest
COPY ./fengwang-matrix /app
WORKDIR /app
RUN make
CMD ["./svdimage"]
