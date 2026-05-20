PORTNAME=	pherb-whisper-worker
DISTVERSION=	0.1.3
CATEGORIES=	www audio
MASTER_SITES=	https://github.com/tuaris/pherb/archive/refs/tags/:pherb
DISTFILES=	v${DISTVERSION}${EXTRACT_SUFX}:pherb
DIST_SUBDIR=	pherb

MAINTAINER=	daniel@morante.net
COMMENT=	NATS-based whisper-cli transcription worker for Pherb
WWW=		https://github.com/tuaris/pherb

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKDIR}/pherb-${DISTVERSION}/LICENSE

USES=		zig:015

ZIG_TUPLE=	nats:github.com/lalinsky/nats.zig/archive/refs/heads/main${EXTRACT_SUFX}:1220643a62efb98d5c7e18c92cf83b0a8146460e9cf755ed795a900db297e6a9a4b9 \
		zio:github.com/lalinsky/zio/archive/refs/tags/v0.8.2${EXTRACT_SUFX}:zio-0.8.2-xHbVVC5jGAAYUMZd_BW5eT-HJb_lf-LCGj4PaLOeEkA2

USE_RC_SUBR=	whisper_worker

SUB_FILES=	whisper_worker
SUB_LIST=	PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/pherb-${DISTVERSION}/cmd/whisper-worker

PLIST_FILES=	bin/whisper-worker

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zig-out/bin/whisper-worker ${STAGEDIR}${PREFIX}/bin/whisper-worker

.include <bsd.port.mk>
