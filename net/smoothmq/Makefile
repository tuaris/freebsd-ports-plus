PORTNAME=	smoothmq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3
CATEGORIES=	net

MAINTAINER=	daniel@morante.net
COMMENT=	An improved drop-in replacement for SQS 
WWW=		https://github.com/poundifdef/smoothmq

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules
GH_ACCOUNT=	poundifdef
GH_PROJECT=	smoothmq

USE_RC_SUBR=	smoothmq

GO_MODULE=	github.com/poundifdef/smoothmq

SMOOTHMQ_USER?=	nobody
SMOOTHMQ_GROUP?=	nobody
SMOOTHMQ_DATADIR?= /var/db/${PORTNAME}

SUB_LIST=	SMOOTHMQ_USER=${SMOOTHMQ_USER} \
			SMOOTHMQ_GROUP=${SMOOTHMQ_GROUP} \
			SMOOTHMQ_DATADIR=${SMOOTHMQ_DATADIR} \

USERS=		${SMOOTHMQ_USER}
GROUPS=		${SMOOTHMQ_GROUP}

PLIST_SUB=	${SUB_LIST}

post-install:
	@${CP} ${WRKSRC}/config.yaml ${STAGEDIR}${PREFIX}/etc/smoothmq.yaml.sample
	@${MKDIR} ${STAGEDIR}${SMOOTHMQ_DATADIR}

.include <bsd.port.mk>
