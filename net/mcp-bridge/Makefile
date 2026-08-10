PORTNAME=	mcp-bridge
DISTVERSION=	0.1.0
CATEGORIES=	net
MASTER_SITES=	https://pacyworld.dev/buenapp/mcp-bridge/archive/
DISTNAME=	v${DISTVERSION}
DIST_SUBDIR=	mcp-bridge

MAINTAINER=	daniel@morante.net
COMMENT=	MCP stdio to HTTP(S) bridge with DANE TLSA verification
WWW=		https://pacyworld.dev/buenapp/mcp-bridge

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig:lang/zig015

MAKE_ENV+=	ZIG_GLOBAL_CACHE_DIR=${WRKDIR}/.zig-cache \
		HOME=${WRKDIR}

WRKSRC=		${WRKDIR}/mcp-bridge

PLIST_FILES=	bin/mcp-bridge

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build \
		-Dtarget=x86_64-freebsd -Doptimize=ReleaseSafe -Dcpu=baseline

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zig-out/bin/mcp-bridge ${STAGEDIR}${PREFIX}/bin/mcp-bridge

.include <bsd.port.mk>
