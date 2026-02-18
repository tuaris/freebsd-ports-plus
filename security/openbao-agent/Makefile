PORTNAME=	openbao-agent
DISTVERSION=	2.4.1
CATEGORIES=	security

MAINTAINER=	jake@metalrip.com
COMMENT=	OpenBao Agent - auto-auth and token sink daemon
WWW=		https://openbao.org/docs/agent-and-proxy/agent/

LICENSE=	MPL20

RUN_DEPENDS=	bao:security/openbao

USES=		metaport

USE_RC_SUBR=	openbao_agent

ETCDIR=		${PREFIX}/etc
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}
_BAOSECRETDIR=	${ETCDIR}/bao

SUB_FILES=	pkg-message-agent
SUB_LIST=	USER=${USERS} \
		GROUP=${GROUPS} \
		BAOSECRETDIR=${_BAOSECRETDIR}

USERS=		openbao
GROUPS=		openbao

PLIST_SUB=	USER=${USERS} GROUP=${GROUPS}

pkg-message=	${WRKDIR}/pkg-message-agent

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d
	@${MKDIR} ${STAGEDIR}${_BAOSECRETDIR}
	@${MKDIR} ${STAGEDIR}/var/run/bao
	${INSTALL_DATA} ${FILESDIR}/bao-agent.hcl.sample \
		${STAGEDIR}${ETCDIR}/bao-agent.hcl.sample
	@${MKDIR} ${STAGEDIR}${ETCDIR}/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/openbao_agent.newsyslog \
		${STAGEDIR}${ETCDIR}/newsyslog.conf.d/openbao_agent.conf
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/openbao_agent.monit \
		${STAGEDIR}${EXAMPLESDIR}/openbao_agent.monit

.include <bsd.port.mk>
