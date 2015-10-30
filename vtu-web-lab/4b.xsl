<?xml version = "1.0"?>
<xsl:stylesheet version = "1.0"
xmlns:xsl = "http://www.w3.org/1999/XSL/Transform"
xmlns = "http://www.w3.org/1999/xhtml" >
<xsl:template match = "students">
<h2> VTU Students' Descriptions </h2>
<xsl:for-each select = "VTU">
<span style = "font-style: italic; color: blue;"> USN: </span>
<xsl:value-of select = "USN" /> <br />
<span style = "font-style: italic; color: blue;"> Name: </span>
<xsl:value-of select = "name" /> <br />
<span style = "font-style: italic; color: blue;"> College: </span>
<xsl:value-of select = "college" /> <br />
<span style = "font-style: italic; color: blue;"> Branch: </span>
<xsl:value-of select = "branch" /> <br />
<span style = "font-style: italic; color: blue;"> Year of Join: </span>
<xsl:value-of select = "YOJ" /> <br />
<span style = "font-style: italic; color: blue;"> E-Mail: </span>
<xsl:value-of select = "email" /> <br /> <br />
</xsl:for-each>
</xsl:template>
</xsl:stylesheet>

