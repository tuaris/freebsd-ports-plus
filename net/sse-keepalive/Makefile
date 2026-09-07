PORTNAME=	sse-keepalive
DISTVERSION=	0.2.0
CATEGORIES=	net
MASTER_SITES=	https://git.morante.net/daniel/sse-keepalive/archive/
DISTNAME=	v${DISTVERSION}
DIST_SUBDIR=	sse-keepalive

MAINTAINER=	daniel@morante.net
COMMENT=	SSE keep-alive shim for streaming LLM providers
WWW=		https://git.morante.net/daniel/sse-keepalive

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 aarch64
ONLY_FOR_ARCHS_REASON=	uses kqueue/SO_REUSEPORT_LB and is only built for these targets

BUILD_DEPENDS=	zig:lang/zig015

USE_RC_SUBR=	sse_keepalive

MAKE_ENV+=	ZIG_GLOBAL_CACHE_DIR=${WRKDIR}/.zig-cache \
		HOME=${WRKDIR}

SUB_LIST=	USER=${USERS} \
		GROUP=${GROUPS} \
		ETCDIR=${ETCDIR}

WRKSRC=		${WRKDIR}/sse-keepalive

USERS=		ssekeepalive
GROUPS=		ssekeepalive

ZIG_TARGET=	${ARCH:S/amd64/x86_64/}-freebsd
ZIG_CPU=	${ARCH:S/amd64/baseline/:S/aarch64/baseline/}

PLIST_FILES=	bin/sse-keepalive \
		bin/sse-responder \
		share/man/man8/sse-keepalive.8.gz \
		"@sample ${ETCDIR}/sse-keepalive.conf.sample"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build install responder \
		-Dtarget=${ZIG_TARGET} -Doptimize=ReleaseSafe -Dcpu=${ZIG_CPU}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zig-out/bin/sse-keepalive ${STAGEDIR}${PREFIX}/bin/sse-keepalive
	${INSTALL_PROGRAM} ${WRKSRC}/zig-out/bin/sse-responder ${STAGEDIR}${PREFIX}/bin/sse-responder
	${INSTALL_MAN} ${WRKSRC}/man/sse-keepalive.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/sse-keepalive.conf.sample \
		${STAGEDIR}${ETCDIR}/sse-keepalive.conf.sample

.include <bsd.port.mk>
