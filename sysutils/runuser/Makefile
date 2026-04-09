PORTNAME=	runuser
PORTVERSION=	1.0.0
CATEGORIES=	sysutils

MAINTAINER=	danny@morante.net
COMMENT=	Linux runuser(1) compatibility shim for FreeBSD
WWW=		https://git.morante.net/FreeBSD/ports

LICENSE=	BSD2CLAUSE

MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	sbin/runuser

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/runuser ${STAGEDIR}${PREFIX}/sbin/runuser

.include <bsd.port.mk>
