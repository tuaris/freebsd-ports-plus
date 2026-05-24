PORTNAME=	pyannote-metrics
DISTVERSION=	4.1
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyannote_metrics-${DISTVERSION}

MAINTAINER=	daniel@morante.net
COMMENT=	Evaluation metrics for speaker diarization
WWW=		https://github.com/pyannote/pyannote-metrics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyannote-core>0:multimedia/py-pyannote-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyannote-database>0:multimedia/py-pyannote-database@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
