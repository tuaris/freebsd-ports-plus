PORTNAME=	pherb
PKGNAMESUFFIX=	-consumer

COMMENT=	Pherb NATS JetStream consumer daemon for speech processing

USES=		php:flavors
USE_PHP=	curl json pcntl pdo pdo_mysql posix

USE_RC_SUBR=	pherb_consumer

USERS=		pherb
GROUPS=		pherb

MASTERDIR=	${.CURDIR}/../pherb
PLIST=		${.CURDIR}/pkg-plist

LIBEXECDIR=	${PREFIX}/libexec/pherb
ETCDIR=		${PREFIX}/etc/pherb

PLIST_SUB=	LIBEXECDIR=${LIBEXECDIR}

SUB_FILES=	pkg-message-consumer pherb_consumer pherb_consumer.newsyslog.conf
SUB_LIST=	LIBEXECDIR=${LIBEXECDIR} \
		ETCDIR=${ETCDIR} \
		PHP=${PHP_CMD:U${LOCALBASE}/bin/php} \
		USERS=${USERS} \
		GROUPS=${GROUPS}
pkg-message=	${WRKDIR}/pkg-message-consumer

do-install:
	@${MKDIR} ${STAGEDIR}${LIBEXECDIR}
	@${MKDIR} ${STAGEDIR}${LIBEXECDIR}/classes
	@${MKDIR} ${STAGEDIR}${LIBEXECDIR}/includes
	@${MKDIR} ${STAGEDIR}${LIBEXECDIR}/libraries
	@${MKDIR} ${STAGEDIR}${LIBEXECDIR}/schema
	@${MKDIR} ${STAGEDIR}${LIBEXECDIR}/system
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pherb-consumer ${STAGEDIR}${LIBEXECDIR}/
	@(cd ${WRKSRC}/classes && ${COPYTREE_SHARE} . ${STAGEDIR}${LIBEXECDIR}/classes)
	${INSTALL_DATA} ${WRKSRC}/config/settings.ini.sample ${STAGEDIR}${ETCDIR}/settings.ini.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${WRKDIR}/pherb_consumer.newsyslog.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/pherb_consumer.conf.sample
	${INSTALL_DATA} ${WRKSRC}/includes/*.php ${STAGEDIR}${LIBEXECDIR}/includes/
	${INSTALL_DATA} ${WRKSRC}/schema/*.sql ${STAGEDIR}${LIBEXECDIR}/schema/
	@(cd ${WRKSRC}/libraries && ${COPYTREE_SHARE} . ${STAGEDIR}${LIBEXECDIR}/libraries)
	@(cd ${WRKSRC}/system && ${COPYTREE_SHARE} . ${STAGEDIR}${LIBEXECDIR}/system)

post-install:
	@${REINPLACE_CMD} 's|/../system/bootstrap.inc.php|/system/bootstrap.inc.php|' \
		${STAGEDIR}${LIBEXECDIR}/pherb-consumer

.include "${MASTERDIR}/Makefile"
