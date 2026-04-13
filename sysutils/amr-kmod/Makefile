PORTNAME=	amr-kmod
PORTVERSION=	0.1.0
CATEGORIES=	sysutils

MAINTAINER=	github@tuaris.com
COMMENT=	LSI Logic MegaRAID SCSI/ATA/SATA RAID controller driver
WWW=		https://github.com/tuaris/freebsd-amr-kmod

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	amr(4) only supports x86 architectures

USES=		kmod

USE_GITHUB=	yes
GH_ACCOUNT=	tuaris
GH_PROJECT=	freebsd-amr-kmod
GH_TAGNAME=	v${PORTVERSION}

WRKSRC_SUBDIR=	modules/amr

SUB_FILES=	pkg-message

PLIST_FILES=	${KMODDIR}/amr.ko \
		${KMODDIR}/amr_cam.ko \
		share/man/man4/amr.4.gz

do-install:
	${INSTALL_KLD} ${WRKSRC}/amr.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_KLD} ${WRKSRC}/amr_cam/amr_cam.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_MAN} ${WRKSRC}/../../man/amr.4 ${STAGEDIR}${PREFIX}/share/man/man4

.include <bsd.port.mk>
