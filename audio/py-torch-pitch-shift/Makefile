PORTNAME=	torch-pitch-shift
DISTVERSION=	1.2.5
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	torch_pitch_shift-${DISTVERSION}

MAINTAINER=	daniel@morante.net
COMMENT=	Pitch-shifting audio with PyTorch
WWW=		https://github.com/KentoNishi/torch-pitch-shift

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchaudio>0:audio/py-torchaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}primePy>0:math/py-primePy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
