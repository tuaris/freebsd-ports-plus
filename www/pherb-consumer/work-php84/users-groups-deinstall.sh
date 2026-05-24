if [ -n "${PKG_ROOTDIR}" ] && [ "${PKG_ROOTDIR}" != "/" ]; then
  PW="/usr/sbin/pw -R ${PKG_ROOTDIR}"
else
  PW=/usr/sbin/pw
fi
if ${PW} usershow pherb >/dev/null 2>&1; then
  echo "==> You should manually remove the \"pherb\" user"
fi
if ${PW} groupshow pherb >/dev/null 2>&1; then
  echo "==> You should manually remove the \"pherb\" group"
fi
