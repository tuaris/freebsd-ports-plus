PORTNAME=	pherb-whisper-worker
DISTVERSION=	0.1.3
CATEGORIES=	www audio
MASTER_SITES=	https://github.com/tuaris/pherb/archive/refs/tags/:pherb \
		https://github.com/lalinsky/nats.zig/archive/refs/heads/:nats \
		https://github.com/lalinsky/zio/archive/refs/tags/:zio
DISTFILES=	v${DISTVERSION}${EXTRACT_SUFX}:pherb \
		main${EXTRACT_SUFX}:nats \
		v0.8.2${EXTRACT_SUFX}:zio
DIST_SUBDIR=	pherb

MAINTAINER=	daniel@morante.net
COMMENT=	NATS-based whisper-cli transcription worker for Pherb
WWW=		https://github.com/tuaris/pherb

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKDIR}/pherb-${DISTVERSION}/LICENSE

BUILD_DEPENDS=	zig:lang/zig

USE_RC_SUBR=	whisper_worker

SUB_FILES=	whisper_worker
SUB_LIST=	PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/pherb-${DISTVERSION}/cmd/whisper-worker
ZIG_DEPSDIR=	${WRKDIR}/zig-packages
NATS_HASH=	1220643a62efb98d5c7e18c92cf83b0a8146460e9cf755ed795a900db297e6a9a4b9
ZIO_HASH=	zio-0.8.2-xHbVVC5jGAAYUMZd_BW5eT-HJb_lf-LCGj4PaLOeEkA2

PLIST_FILES=	bin/whisper-worker

MAKE_ENV+=	ZIG_GLOBAL_CACHE_DIR=${WRKDIR}/.zig-cache \
		HOME=${WRKDIR}

post-extract:
	@${MKDIR} ${ZIG_DEPSDIR}
	@${MV} ${WRKDIR}/nats.zig-main ${ZIG_DEPSDIR}/${NATS_HASH}
	@${MV} ${WRKDIR}/zio-0.8.2 ${ZIG_DEPSDIR}/${ZIO_HASH}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build \
		-Doptimize=ReleaseSafe -Dcpu=baseline \
		--system ${ZIG_DEPSDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zig-out/bin/whisper-worker ${STAGEDIR}${PREFIX}/bin/whisper-worker

.include <bsd.port.mk>
