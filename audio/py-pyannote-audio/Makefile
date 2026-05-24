PORTNAME=	pyannote-audio
DISTVERSION=	4.0.4
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyannote_audio-${DISTVERSION}

MAINTAINER=	daniel@morante.net
COMMENT=	State-of-the-art speaker diarization toolkit
WWW=		https://github.com/pyannote/pyannote-audio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asteroid-filterbanks>0:audio/py-asteroid-filterbanks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}einops>0:misc/py-einops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface-hub>0:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch-lightning>0:misc/py-pytorch-lightning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>0:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp>0:devel/py-opentelemetry-exporter-otlp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>0:devel/py-opentelemetry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyannote-core>0:multimedia/py-pyannote-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyannote-database>0:multimedia/py-pyannote-database@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyannote-metrics>0:multimedia/py-pyannote-metrics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyannote-pipeline>0:multimedia/py-pyannote-pipeline@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyannoteai-sdk>0:www/py-pyannoteai-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch-metric-learning>0:misc/py-pytorch-metric-learning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>0:misc/py-safetensors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torch-audiomentations>0:audio/py-torch-audiomentations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchaudio>0:audio/py-torchaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchcodec>0:multimedia/py-torchcodec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchmetrics>0:misc/py-torchmetrics@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
