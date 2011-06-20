<?xml version="1.0" encoding="ASCII"?>
<!--

 adprj.xsl - a util xsl for Android's repo project operation.

 It's help to find/list the projects for .repo/manifests/default.xml

 [Usage]
  xsltproc adproj.xsl [.repo/manifests/default.xml]

  If didn't specify the XML, default is .repo/manifests/default.xml.
  More help can be found in the document.
  -->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" version="1.0" encoding="UTF-8"/>
    <xsl:param name="level" select="1"/>
    <xsl:strip-space elements="*"/>
    <xsl:template match="/manifest">
        <xsl:for-each select="/manifest/project">
path:<xsl:value-of select="@path"/> name:<xsl:value-of select="@name"/>
        </xsl:for-each>
The count:<xsl:value-of select="count(/manifest/project)"/>
    </xsl:template>
</xsl:stylesheet>
