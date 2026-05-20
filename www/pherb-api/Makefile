PORTNAME=	pherb
PKGNAMESUFFIX=	-api

COMMENT=	Pherb REST API for speech processing orchestration

USES=		php:flavors
USE_PHP=	curl filter json pdo pdo_mysql

WWWDIR=		${PREFIX}/www/pherb

MASTERDIR=	${.CURDIR}/../pherb
PLIST=		${.CURDIR}/pkg-plist

SUB_FILES=	pkg-message-api
pkg-message=	${WRKDIR}/pkg-message-api

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/api
	@${MKDIR} ${STAGEDIR}${WWWDIR}/classes
	@${MKDIR} ${STAGEDIR}${WWWDIR}/config
	@${MKDIR} ${STAGEDIR}${WWWDIR}/includes
	@${MKDIR} ${STAGEDIR}${WWWDIR}/libraries
	@${MKDIR} ${STAGEDIR}${WWWDIR}/system
	${INSTALL_DATA} ${WRKSRC}/api/.htaccess ${STAGEDIR}${WWWDIR}/api/.htaccess
	${INSTALL_DATA} ${WRKSRC}/api/index.php ${STAGEDIR}${WWWDIR}/api/index.php
	@(cd ${WRKSRC}/classes && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/classes)
	${INSTALL_DATA} ${WRKSRC}/config/settings.ini.sample ${STAGEDIR}${WWWDIR}/config/
	${INSTALL_DATA} ${WRKSRC}/includes/*.php ${STAGEDIR}${WWWDIR}/includes/
	@(cd ${WRKSRC}/libraries && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/libraries)
	@(cd ${WRKSRC}/system && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/system)

.include "${MASTERDIR}/Makefile"
