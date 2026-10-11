PORTNAME=	mcp-grafana
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	www

MAINTAINER=	daniel@morante.net
COMMENT=	Model Context Protocol server for Grafana and its ecosystem
WWW=		https://github.com/grafana/mcp-grafana

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# go.mod requires go 1.26.5; the ports framework pins GOTOOLCHAIN to local,
# so a go126 older than that fails the build instead of downloading a newer one.
USES=		go:1.26+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	grafana

USE_RC_SUBR=	mcp_grafana
SUB_FILES=	pkg-message

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}/v2
GO_MOD_DIST=	github
GO_TARGET=	./cmd/mcp-grafana
GO_LDFLAGS=	-X ${GO_MODULE}.version=${DISTVERSION}

MCP_GRAFANA_USER?=	mcpgrafana
MCP_GRAFANA_GROUP?=	mcpgrafana

USERS=		${MCP_GRAFANA_USER}
GROUPS=		${MCP_GRAFANA_GROUP}

SUB_LIST=	MCP_GRAFANA_GROUP=${MCP_GRAFANA_GROUP} \
		MCP_GRAFANA_USER=${MCP_GRAFANA_USER}
PLIST_SUB=	${SUB_LIST}

post-install:
	${INSTALL_DATA} ${FILESDIR}/mcp_grafana.env.sample \
		${STAGEDIR}${PREFIX}/etc/mcp_grafana.env.sample

.include <bsd.port.mk>
