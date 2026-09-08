PORTNAME=	mcp-bridge
DISTVERSION=	0.1.4
CATEGORIES=	net
MASTER_SITES=	https://pacyworld.dev/buenapp/mcp-bridge/archive/ \
		https://pacyworld.dev/pacyworld/born/archive/:born
DISTNAME=	v${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} v${BORN_VERSION}.tar.gz:born
DIST_SUBDIR=	mcp-bridge

# mcp-bridge >= 0.1.4 vendors the event port / socket layer from born.
# zig fetches it at build time, but poudriere jails have no network —
# pre-seed zig's global cache in post-extract instead. The hash is pinned
# in the port's build.zig.zon; a stale seed fails the build loudly, never
# silently.
BORN_VERSION=	0.2.0
BORN_HASH=	born-${BORN_VERSION}-Yg13wId6AQAEbZ1E8FwmJLVX7gsDO_zqNbtz3vpki8UU

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

post-extract:
	@${MKDIR} ${WRKDIR}/.zig-cache/p/${BORN_HASH}
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/v${BORN_VERSION}.tar.gz \
		--strip-components 1 -C ${WRKDIR}/.zig-cache/p/${BORN_HASH}/

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build \
		-Dtarget=x86_64-freebsd -Doptimize=ReleaseSafe -Dcpu=baseline

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zig-out/bin/mcp-bridge ${STAGEDIR}${PREFIX}/bin/mcp-bridge

.include <bsd.port.mk>
