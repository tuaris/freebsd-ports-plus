PORTNAME=	pherb-worker
DISTVERSION=	0.4.0
CATEGORIES=	www audio
MASTER_SITES=	https://github.com/tuaris/pherb/archive/refs/tags/:pherb
DISTFILES=	v${DISTVERSION}${EXTRACT_SUFX}:pherb
DIST_SUBDIR=	pherb

MAINTAINER=	daniel@morante.net
COMMENT=	Multi-stage ML pipeline worker for Pherb
WWW=		https://github.com/tuaris/pherb

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKDIR}/pherb-${DISTVERSION}/LICENSE

USES=		zig:015

ZIG_TUPLE=	nats:github.com/lalinsky/nats.zig/archive/refs/heads/main.tar.gz:1220643a62efb98d5c7e18c92cf83b0a8146460e9cf755ed795a900db297e6a9a4b9 \
		zio:github.com/lalinsky/zio/archive/3ac234eae165177cd75742f922851dc5d.tar.gz:zio-0.8.2-xHbVVC5jGAAYUMZd_BW5eT-HJb_lf-LCGj4PaLOeEkA2

CONFLICTS_INSTALL=	pherb-whisper-worker

USE_RC_SUBR=	pherb_worker

SUB_FILES=	pherb_worker
SUB_LIST=	PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/pherb-${DISTVERSION}/cmd/pherb-worker

PLIST_FILES=	bin/pherb-worker

.include <bsd.port.mk>
