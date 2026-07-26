PORTNAME=	securedkim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	mail
MASTER_SITES=	https://pacyworld.dev/securemessage/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	daniel@morante.net
COMMENT=	RFC 6376 DKIM signing and verification milter (high-performance Zig implementation)
WWW=		https://pacyworld.dev/securemessage/securedkim

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		pkgconfig ssl zig:015

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

USE_RC_SUBR=	securedkim

USERS=		_dkim
GROUPS=		_dkim

PLIST_FILES=	bin/securedkim \
		"@sample ${ETCDIR}/securedkim.conf.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/securedkim.conf.sample \
		${STAGEDIR}${ETCDIR}/securedkim.conf.sample

.include <bsd.port.mk>
