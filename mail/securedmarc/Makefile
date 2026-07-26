PORTNAME=	securedmarc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	mail
MASTER_SITES=	https://pacyworld.dev/securemessage/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	daniel@morante.net
COMMENT=	RFC 7489 DMARC policy evaluation milter (high-performance Zig implementation)
WWW=		https://pacyworld.dev/securemessage/securedmarc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		pkgconfig ssl zig:015

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

USE_RC_SUBR=	securedmarc

USERS=		_dmarc
GROUPS=		_dmarc

PLIST_FILES=	bin/securedmarc \
		"@sample ${ETCDIR}/securedmarc.conf.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/securedmarc.conf.sample \
		${STAGEDIR}${ETCDIR}/securedmarc.conf.sample

.include <bsd.port.mk>
