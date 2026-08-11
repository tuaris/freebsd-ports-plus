PORTNAME=	securearc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
CATEGORIES=	mail
MASTER_SITES=	https://pacyworld.dev/securemessage/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	daniel@morante.net
COMMENT=	RFC 8617 ARC chain validation and sealing milter (Zig implementation)
WWW=		https://pacyworld.dev/securemessage/securearc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		pkgconfig ssl zig:015
ZIG_TUPLE=	securemilter:pacyworld.dev/securemessage/securemilter-lib/archive/v0.5.0.tar.gz?dummy=/securemilter-lib-0.5.0.tar.gz:securemilter_lib-0.5.0-IbMuLIdYBgDkEFPMw0Ljic0E72eVSanLG-bqI8_jk4tQ \
		securemilter_crypto:pacyworld.dev/securemessage/securemilter-crypto/archive/v0.2.0.tar.gz?dummy=/securemilter-crypto-0.2.0.tar.gz:securemilter_crypto-0.2.0-R5f4teC4AQDi_T_GQlhZBgbefsXXBUrgVhe7i0pANT-4

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

USE_RC_SUBR=	securearc

PLIST_FILES=	bin/securearc \
		bin/securearc-check \
		bin/securearc-seal \
		bin/securearc-testkey \
		share/man/man8/securearc.8.gz \
		share/man/man8/securearc-check.8.gz \
		share/man/man8/securearc-seal.8.gz \
		share/man/man8/securearc-testkey.8.gz \
		"@sample ${ETCDIR}/securearc.conf.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/securearc.conf.sample \
		${STAGEDIR}${ETCDIR}/securearc.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/securearc.8 ${WRKSRC}/man/securearc-check.8 \
		${WRKSRC}/man/securearc-seal.8 ${WRKSRC}/man/securearc-testkey.8 \
		${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
