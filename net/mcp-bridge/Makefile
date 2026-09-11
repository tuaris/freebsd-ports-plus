PORTNAME=	mcp-bridge
DISTVERSION=	0.1.6
CATEGORIES=	net
MASTER_SITES=	https://pacyworld.dev/buenapp/mcp-bridge/archive/v${DISTVERSION}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	mcp-bridge

MAINTAINER=	daniel@morante.net
COMMENT=	MCP stdio to HTTP(S) bridge with DANE TLSA verification
WWW=		https://pacyworld.dev/buenapp/mcp-bridge

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# Links base OpenSSL by absolute path, so TLS trust follows certctl
# (/etc/ssl). USES=ssl is omitted on purpose: it tracks DEFAULT_VERSIONS,
# and with ssl=base it fails check-depends on hosts that have ports OpenSSL
# installed. The stage-qa warning "you need USES=ssl" is expected.

USES=		zig:015
ZIG_TUPLE=	born:pacyworld.dev/pacyworld/born/archive/v0.2.3.tar.gz?dummy=/born-0.2.3.tar.gz:born-0.2.3-Yg13wDXNAQAJVezbT1dqiuH3fTz0pgxG-7fTf-7AOWsF
ZIG_ARGS=	-Dtarget=x86_64-freebsd

WRKSRC=		${WRKDIR}/mcp-bridge

PLIST_FILES=	bin/mcp-bridge

.include <bsd.port.mk>
