PORTNAME=	mac_do_auto
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	sysutils
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	daniel@morante.net
COMMENT=	MAC policy for transparent privilege escalation by group membership
WWW=		https://github.com/tuaris/mac_do_auto

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod uidfix zig:015

USE_GITHUB=	yes
GH_ACCOUNT=	tuaris

USE_RC_SUBR=	autodo_eventd

ETCDIR=		${PREFIX}/etc/autodo

SUB_FILES=	pkg-message
SUB_LIST=	KMODDIR=${KMODDIR} \
		ETCDIR=${ETCDIR}

BUILD_WRKSRC=	${WRKSRC}/daemon

PLIST_FILES=	${KMODDIR}/mac_do_auto.ko

# The kernel module has its own make(1) build; zig.mk handles the daemon
# (its do-build is a no-op, the daemon is compiled during do-install).
do-build:
	@(cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${ALL_TARGET})

post-install:
	${INSTALL_KLD} ${WRKSRC}/src/mac_do_auto.ko ${STAGEDIR}${KMODDIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}/profiles
	${INSTALL_DATA} ${WRKSRC}/config/autodo.conf.sample \
		${STAGEDIR}${ETCDIR}/autodo.conf.sample
	${INSTALL_DATA} ${WRKSRC}/config/profiles/*.conf \
		${STAGEDIR}${ETCDIR}/profiles/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man4 \
		${STAGEDIR}${PREFIX}/share/man/man5 \
		${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/mac_do_auto.4 \
		${STAGEDIR}${PREFIX}/share/man/man4/
	${INSTALL_MAN} ${WRKSRC}/man/autodo.conf.5 \
		${STAGEDIR}${PREFIX}/share/man/man5/
	${INSTALL_MAN} ${WRKSRC}/man/autodo-eventd.8 \
		${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
