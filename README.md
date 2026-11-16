# Extra Ports

Extra FreeBSD ports not yet available in the official FreeBSD ports tree. Pre-built packages are available via the **Ports Plus** repository.

## Available Ports

| Port | Description |
|------|-------------|
| `databases/arcadedb` | ArcadeDB - Multi-model database (pending upstream PR) |
| `databases/mongodb50` | MongoDB Community Edition 5.0.x (preserved after upstream EOL removal) |
| `databases/mongodb60` | MongoDB Community Edition 6.0.x (preserved after upstream EOL removal) |
| `misc/opencode` | OpenCode AI coding agent — FreeBSD SIGUSR1 fix (overrides the official port pending upstream acceptance) |
| `misc/opencode-server` | Boot service (rc.d) for the OpenCode AI coding agent server |
| `net-p2p/bfgminer` | BFGMiner - Modular ASIC/FPGA Bitcoin miner (FreeBSD fork) |
| `net-p2p/cpuminer-opt` | CPU miner with architecture-specific optimizations |
| `net/pecl-zmq` | PHP ZMQ extension - ZeroMQ bindings (PHP 8.5 patched) |
| `net/smoothmq` | SmoothMQ - Drop-in SQS replacement with UI and observability |
| `net/sse-keepalive` | SSE keep-alive shim for streaming LLM providers (kqueue, multi-process) |
| `security/openbao-agent` | OpenBao Agent - auto-auth and token sink daemon |
| `sysutils/terragrunt487` | Terragrunt 0.48.7 - Thin wrapper for Terraform |
| `www/sunlight` | Sunlight - Certificate Transparency log implementation |

> **Note:** `security/openbao` is already part of the official FreeBSD ports tree and does not need this overlay.

> **Note:** `misc/opencode-server` installs only the boot service; the `opencode` binary is a runtime dependency. This overlay carries a patched `misc/opencode` (the FreeBSD SIGUSR1 heap-listener fix, proposed upstream as anomalyco/opencode#64312) that shadows the official port, so the fixed binary is available here before the official maintainer accepts the change. Once the fix lands in the official tree, the overlay's `misc/opencode` can be dropped.

## Enabling the Ports Plus Repository

Packages are built weekly against the latest FreeBSD quarterly ports branch for supported FreeBSD versions.

To install packages from this repository, create the following configuration file:

```sh
mkdir -p /usr/local/etc/pkg/repos
cat > /usr/local/etc/pkg/repos/PortsPlus.conf << 'CONF'
PortsPlus: {
  url: "http://pkg.morante.net/plus/${ABI}",
  enabled: yes
}
CONF
```

Then update the package catalog and install:

```sh
pkg update
pkg install openbao-agent bfgminer cpuminer-opt
```

## Supported Versions

| FreeBSD Version | ABI |
|-----------------|-----|
| 13.5 | `FreeBSD:13:amd64` |
| 14.3 | `FreeBSD:14:amd64` |
| 15.0 | `FreeBSD:15:amd64` |

## Contributing

To add a new port to the overlay, create the standard FreeBSD port directory structure under the appropriate category. Ports added here will be automatically included in the next scheduled build.

## License

Individual ports are licensed under their respective licenses. See each port's `Makefile` for details.
