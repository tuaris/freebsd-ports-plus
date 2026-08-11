PORTNAME=	securedkim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
CATEGORIES=	mail

USE_GITHUB=	yes
GH_ACCOUNT=	securemessage

MAINTAINER=	daniel@morante.net
COMMENT=	RFC 6376 DKIM signing and verification milter (Zig implementation)
WWW=		https://pacyworld.dev/securemessage/securedkim

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		pkgconfig ssl zig:015
ZIG_TUPLE=	securemilter:github.com/securemessage/securemilter-lib/archive/refs/tags/v0.5.0.tar.gz?dummy=/securemilter-lib-0.5.0.tar.gz:securemilter_lib-0.5.0-IbMuLIdYBgDkEFPMw0Ljic0E72eVSanLG-bqI8_jk4tQ \
		securemilter_crypto:github.com/securemessage/securemilter-crypto/archive/refs/tags/v0.2.0.tar.gz?dummy=/securemilter-crypto-0.2.0.tar.gz:securemilter_crypto-0.2.0-R5f4teC4AQDi_T_GQlhZBgbefsXXBUrgVhe7i0pANT-4

USE_RC_SUBR=	securedkim

PLIST_FILES=	bin/securedkim \
		bin/securedkim-check \
		bin/securedkim-genkey \
		bin/securedkim-sign \
		bin/securedkim-testkey \
		share/man/man8/securedkim.8.gz \
		share/man/man8/securedkim-check.8.gz \
		share/man/man8/securedkim-genkey.8.gz \
		share/man/man8/securedkim-sign.8.gz \
		share/man/man8/securedkim-testkey.8.gz \
		"@sample ${ETCDIR}/securedkim.conf.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/securedkim.conf.sample \
		${STAGEDIR}${ETCDIR}/securedkim.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/securedkim.8 ${WRKSRC}/man/securedkim-check.8 \
		${WRKSRC}/man/securedkim-genkey.8 ${WRKSRC}/man/securedkim-sign.8 \
		${WRKSRC}/man/securedkim-testkey.8 \
		${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
