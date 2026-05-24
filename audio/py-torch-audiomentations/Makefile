PORTNAME=	torch-audiomentations
DISTVERSION=	0.12.0
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	torch_audiomentations-${DISTVERSION}

MAINTAINER=	daniel@morante.net
COMMENT=	Fast audio data augmentation in PyTorch
WWW=		https://github.com/asteroid-team/torch-audiomentations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}julius>0:audio/py-julius@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchaudio>0:audio/py-torchaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torch-pitch-shift>0:audio/py-torch-pitch-shift@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
