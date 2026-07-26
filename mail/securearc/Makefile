PORTNAME=	securearc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	mail
MASTER_SITES=	https://pacyworld.dev/securemessage/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	daniel@morante.net
COMMENT=	RFC 8617 ARC chain validation and sealing milter (high-performance Zig implementation)
WWW=		https://pacyworld.dev/securemessage/securearc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		pkgconfig ssl zig:015

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

USE_RC_SUBR=	securearc

USERS=		_arc
GROUPS=		_arc

PLIST_FILES=	bin/securearc \
		bin/securearc-testkey \
		"@sample ${ETCDIR}/securearc.conf.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/securearc.conf.sample \
		${STAGEDIR}${ETCDIR}/securearc.conf.sample

.include <bsd.port.mk>
