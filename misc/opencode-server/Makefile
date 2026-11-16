PORTNAME=	opencode
DISTVERSION=	2.3.0
CATEGORIES=	misc
PKGNAMESUFFIX=	-server
DISTFILES=

MAINTAINER=	daniel@morante.net
COMMENT=	Boot service for the OpenCode AI coding agent
WWW=		https://opencode.ai/

LICENSE=	MIT

RUN_DEPENDS=	curl:ftp/curl \
		opencode>0:misc/opencode

USES=		python:3.12,run
USE_RC_SUBR=	opencode_serve

NO_ARCH=	yes
NO_BUILD=	yes

OPENCODE_USER?=		${PORTNAME}
OPENCODE_GROUP?=	${PORTNAME}
OPENCODE_DATADIR?=	/var/db/${PORTNAME}

SUB_LIST=	OPENCODE_DATADIR=${OPENCODE_DATADIR} \
		OPENCODE_GROUP=${OPENCODE_GROUP} \
		OPENCODE_USER=${OPENCODE_USER} \
		PYTHON_CMD=${PYTHON_CMD}

NO_WRKSUBDIR=	yes

.if ${OPENCODE_USER} == ${PORTNAME}
USERS=		${OPENCODE_USER}
.endif
.if ${OPENCODE_GROUP} == ${PORTNAME}
GROUPS=		${OPENCODE_GROUP}
.endif

PLIST_SUB=	${SUB_LIST}

do-extract:
	@${MKDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA} ${FILESDIR}/opencode_serve.env.sample ${STAGEDIR}${PREFIX}/etc/opencode_serve.env.sample
	@${MKDIR} ${STAGEDIR}${OPENCODE_DATADIR}

.include <bsd.port.mk>
