PORTNAME=	securespf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	mail
MASTER_SITES=	https://pacyworld.dev/securemessage/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	daniel@morante.net
COMMENT=	RFC 7208 SPF verification milter (high-performance Zig implementation)
WWW=		https://pacyworld.dev/securemessage/securespf

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		pkgconfig ssl zig:015

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

USE_RC_SUBR=	securespf

USERS=		_spf
GROUPS=		_spf

PLIST_FILES=	bin/securespf \
		"@sample ${ETCDIR}/securespf.conf.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/securespf.conf.sample \
		${STAGEDIR}${ETCDIR}/securespf.conf.sample

.include <bsd.port.mk>
