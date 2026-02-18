PORTNAME=	arcadedb
DISTVERSION=	26.1.1
CATEGORIES=	databases java
MASTER_SITES=	https://github.com/ArcadeData/arcadedb/releases/download/${DISTVERSION}/

MAINTAINER=	daniel@morante.net
COMMENT=	Multi-model database with graph, document, and key-value support
WWW=		https://arcadedb.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe java:run
JAVA_VERSION=	21+
JAVA_VENDOR=	openjdk
USE_RC_SUBR=	arcadedb

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	JAVA=${JAVA} \
		JAVA_HOME=${JAVA_HOME} \
		PREFIX=${PREFIX} \
		DATADIR=${DATADIR} \
		ARCADEDB_USER=${USERS} \
		ARCADEDB_GROUP=${GROUPS}

USERS=		arcadedb
GROUPS=		arcadedb

PLIST_SUB=	ARCADEDB_USER=${USERS} \
		ARCADEDB_GROUP=${GROUPS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%JAVA_HOME%%|${JAVA_HOME}|g' \
		${WRKSRC}/bin/server.sh

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/lib
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${MKDIR} ${STAGEDIR}/var/db/arcadedb/config
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/lib)
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${STAGEDIR}${DATADIR}/bin/
	${INSTALL_DATA} ${WRKSRC}/config/* ${STAGEDIR}/var/db/arcadedb/config/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
