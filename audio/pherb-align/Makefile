PORTNAME=	pherb-align
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	audio python

MAINTAINER=	daniel@morante.net
COMMENT=	Wav2vec2 forced word-level alignment stage for Pherb
WWW=		https://github.com/tuaris/pherb

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchaudio>0:audio/py-torchaudio@${PY_FLAVOR}

USES=		python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	tuaris
GH_PROJECT=	pherb

SHEBANG_FILES=	examples/pherb-align.py

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	libexec/pherb/pherb-align.py

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/pherb
	${INSTALL_SCRIPT} ${WRKSRC}/examples/pherb-align.py \
		${STAGEDIR}${PREFIX}/libexec/pherb/pherb-align.py

.include <bsd.port.mk>
