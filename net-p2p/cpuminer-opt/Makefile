PORTNAME=	cpuminer-opt
DISTVERSION=	26.1
CATEGORIES=	net-p2p
MASTER_SITES=	GH

MAINTAINER=	daniel@morante.net
COMMENT=	Optimized multi-algorithm CPU miner for cryptocurrencies
WWW=		https://github.com/JayDDee/cpuminer-opt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	autoconf:devel/autoconf \
		automake:devel/automake
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjansson.so:devel/jansson \
		libgmp.so:math/gmp

USES=		autoreconf gmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	JayDDee
GH_TAGNAME=	v${DISTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-curl=${LOCALBASE}
CONFIGURE_ENV=	CFLAGS="-O3 -march=native -Wall"

ONLY_FOR_ARCHS=	amd64 aarch64

PLIST_FILES=	bin/cpuminer

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README.md RELEASE_NOTES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpuminer ${STAGEDIR}${PREFIX}/bin/cpuminer

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
