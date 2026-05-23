PORTNAME?=	pherb
PORTVERSION=	0.5.4
CATEGORIES=	www
MASTER_SITES=	https://github.com/tuaris/pherb/archive/refs/tags/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	pherb
WRKSRC=		${WRKDIR}/pherb-${PORTVERSION}

MAINTAINER?=	daniel@morante.net
COMMENT?=	Pherb speech processing orchestrator
WWW?=		https://github.com/tuaris/pherb

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/README.md

NO_ARCH=	yes
NO_BUILD=	yes

# Master port (meta-port) installs all components
.if !defined(PKGNAMESUFFIX)
RUN_DEPENDS=	pherb-api>0:www/pherb-api \
		pherb-consumer>0:www/pherb-consumer

do-install:
	@${DO_NADA}
.endif

.include <bsd.port.mk>
