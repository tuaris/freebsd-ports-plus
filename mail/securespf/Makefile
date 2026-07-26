PORTNAME=	securespf
DISTVERSION=	0.1.0
CATEGORIES=	mail
MASTER_SITES=	https://pacyworld.dev/api/packages/securemessage/generic/${PORTNAME}/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	daniel@morante.net
COMMENT=	RFC 7208 SPF verification milter (high-performance Zig implementation)
WWW=		https://pacyworld.dev/securemessage/securespf

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zig:015

USE_RC_SUBR=	securespf

WRKSRC=		${WRKDIR}/securespf-port/securespf

USERS=		_spf
GROUPS=		_spf

ETCDIR=		${PREFIX}/etc/securespf

PLIST_FILES=	bin/securespf \
		"@sample ${ETCDIR}/securespf.conf.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/securespf.conf.sample \
		${STAGEDIR}${ETCDIR}/securespf.conf.sample

.include <bsd.port.mk>
