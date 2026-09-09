PORTNAME=	mcp-bridge
DISTVERSION=	0.1.4
CATEGORIES=	net
MASTER_SITES=	https://pacyworld.dev/buenapp/mcp-bridge/archive/
DISTNAME=	v${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	mcp-bridge

MAINTAINER=	daniel@morante.net
COMMENT=	MCP stdio to HTTP(S) bridge with DANE TLSA verification
WWW=		https://pacyworld.dev/buenapp/mcp-bridge

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zig:015
ZIG_TUPLE=	born:pacyworld.dev/pacyworld/born/archive/v0.2.0.tar.gz:born-0.2.0-Yg13wId6AQAEbZ1E8FwmJLVX7gsDO_zqNbtz3vpki8UU
ZIG_ARGS=	-Dtarget=x86_64-freebsd

WRKSRC=		${WRKDIR}/mcp-bridge

PLIST_FILES=	bin/mcp-bridge

.include <bsd.port.mk>
