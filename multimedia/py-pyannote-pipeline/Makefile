PORTNAME=	pyannote-pipeline
DISTVERSION=	4.0.0
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyannote_pipeline-${DISTVERSION}

MAINTAINER=	daniel@morante.net
COMMENT=	Hyperparameter tuning for pyannote pipelines
WWW=		https://github.com/pyannote/pyannote-pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}optuna>0:misc/py-optuna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyannote-core>0:multimedia/py-pyannote-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyannote-database>0:multimedia/py-pyannote-database@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
