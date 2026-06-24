FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04

RUN apt-get update && apt-get install -y \
    gcc-riscv64-linux-gnu \
    binutils-riscv64-linux-gnu \
    qemu-user \
    qemu-user-static \
    gdb-multiarch \
    && rm -rf /var/lib/apt/lists/*