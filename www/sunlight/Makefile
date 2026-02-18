PORTNAME=	sunlight
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	www

MAINTAINER=	daniel@morante.net
COMMENT=	Certificate Transparency log implementation and monitoring API
WWW=		https://sunlight.dev/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules

USE_RC_SUBR=	sunlight

GO_MODULE=	filippo.io/sunlight
GO_TARGET=  ./cmd/sunlight:sunlight

SUNLIGHT_USER?=	www
SUNLIGHT_GROUP?=	www
SUNLIGHT_DBDIR?= /var/db/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	SUNLIGHT_USER=${SUNLIGHT_USER} \
			SUNLIGHT_GROUP=${SUNLIGHT_GROUP} \
			SUNLIGHT_CONFIG=${ETCDIR}.yaml.sample \
			SUNLIGHT_DBDIR=${SUNLIGHT_DBDIR}

USERS=		${SUNLIGHT_USER}
GROUPS=		${SUNLIGHT_GROUP}

PLIST_SUB=	${SUB_LIST}

post-install:
	@${CP} ${FILESDIR}/config.yaml ${STAGEDIR}${ETCDIR}.yaml.sample
	@${MKDIR} ${STAGEDIR}${SUNLIGHT_DBDIR}

.include <bsd.port.mk>
