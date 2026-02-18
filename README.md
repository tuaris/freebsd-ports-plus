# Extra Ports

Extra FreeBSD ports not yet available in the official FreeBSD ports tree. Pre-built packages are available via the **Ports Plus** repository.

## Available Ports

| Port | Description |
|------|-------------|
| `security/openbao` | OpenBao - Tool for securely accessing secrets |
| `security/openbao-agent` | OpenBao Agent - auto-auth and token sink daemon |

## Enabling the Ports Plus Repository

Packages are built weekly against the latest FreeBSD quarterly ports branch for supported FreeBSD versions.

To install packages from this repository, create the following configuration file:

```sh
mkdir -p /usr/local/etc/pkg/repos
cat > /usr/local/etc/pkg/repos/MorantePortsPlus.conf << 'EOF'
MorantePortsPlus: {
  url: "pkg+http://pkg.morante.net/plus/${ABI}",
  enabled: yes
}
EOF
```

Then update the package catalog and install:

```sh
pkg update
pkg install openbao openbao-agent
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
