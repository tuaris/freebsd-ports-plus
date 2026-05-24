PORTNAME=	pherb-diarize
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.5
CATEGORIES=	audio python

MAINTAINER=	daniel@morante.net
COMMENT=	Pyannote speaker diarization stage for Pherb
WWW=		https://github.com/tuaris/pherb

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyannote-audio>0:audio/py-pyannote-audio@${PY_FLAVOR}

USES=		python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	tuaris
GH_PROJECT=	pherb

SHEBANG_FILES=	examples/pherb-diarize.py

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	libexec/pherb/pherb-diarize.py

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/pherb
	${INSTALL_SCRIPT} ${WRKSRC}/examples/pherb-diarize.py \
		${STAGEDIR}${PREFIX}/libexec/pherb/pherb-diarize.py

.include <bsd.port.mk>
