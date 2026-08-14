PORTNAME=	securearc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.8
CATEGORIES=	mail

USE_GITHUB=	yes
GH_ACCOUNT=	securemessage

MAINTAINER=	daniel@morante.net
COMMENT=	RFC 8617 ARC chain validation and sealing milter (Zig implementation)
WWW=		https://pacyworld.dev/securemessage/securearc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		pkgconfig ssl zig:015
ZIG_TUPLE=	securemilter:github.com/securemessage/securemilter-lib/archive/refs/tags/v0.5.8.tar.gz?dummy=/securemilter-lib-0.5.8.tar.gz:securemilter_lib-0.5.8-IbMuLPPMBwBFF_ZkUCv-NM8JZjfkW3co0AVx6KnH7nbi \
		securemilter_crypto:github.com/securemessage/securemilter-crypto/archive/refs/tags/v0.2.1.tar.gz?dummy=/securemilter-crypto-0.2.1.tar.gz:securemilter_crypto-0.2.1-R5f4tY--AQD6pZz1ZXfRpnsMIzZTxt6Hi7Vk6OEm12Fk

USE_RC_SUBR=	securearc

PLIST_FILES=	bin/securearc \
		bin/securearc-check \
		bin/securearc-seal \
		bin/securearc-testkey \
		share/man/man8/securearc.8.gz \
		share/man/man8/securearc-check.8.gz \
		share/man/man8/securearc-seal.8.gz \
		share/man/man8/securearc-testkey.8.gz \
		"@sample ${ETCDIR}/securearc.conf.sample" \
		"@dir(mailnull,mail,0750) /var/db/securearc/keys" \
		"@dir(mailnull,mail,0750) /var/db/securearc"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/securearc.conf.sample \
		${STAGEDIR}${ETCDIR}/securearc.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/securearc.8 ${WRKSRC}/man/securearc-check.8 \
		${WRKSRC}/man/securearc-seal.8 ${WRKSRC}/man/securearc-testkey.8 \
		${STAGEDIR}${PREFIX}/share/man/man8/
	@${MKDIR} ${STAGEDIR}/var/db/securearc/keys

.include <bsd.port.mk>
