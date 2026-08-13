PORTNAME=	securedmarc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.6
CATEGORIES=	mail

USE_GITHUB=	yes
GH_ACCOUNT=	securemessage

MAINTAINER=	daniel@morante.net
COMMENT=	RFC 7489 DMARC policy evaluation milter (Zig implementation)
WWW=		https://pacyworld.dev/securemessage/securedmarc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		pkgconfig zig:015
ZIG_TUPLE=	securemilter:github.com/securemessage/securemilter-lib/archive/refs/tags/v0.5.7.tar.gz?dummy=/securemilter-lib-0.5.7.tar.gz:securemilter_lib-0.5.7-IbMuLDFDBwARObjKmzjja8sDCDOu0McOaCv5zwxL7j1-

USE_RC_SUBR=	securedmarc

PLIST_FILES=	bin/securedmarc \
		bin/securedmarc-check \
		share/man/man8/securedmarc.8.gz \
		share/man/man8/securedmarc-check.8.gz \
		"@sample ${ETCDIR}/securedmarc.conf.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/securedmarc.conf.sample \
		${STAGEDIR}${ETCDIR}/securedmarc.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/securedmarc.8 ${WRKSRC}/man/securedmarc-check.8 \
		${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
