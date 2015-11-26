<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/student">
        <html>
            <table border="1">
                <tr>
                    <th>USN</th><th>Name</th><th>College</th><th>Branch</th><th>Year Of Joining</th><th>Email-ID</th>
                </tr>
                <xsl:for-each select="info">
                    <tr>
                        <td><xsl:value-of select="usn" /></td>
                        <td><xsl:value-of select="name" /></td>
                        <td><xsl:value-of select="coll" /></td>
                        <td><xsl:value-of select="branch" /></td>
                        <td><xsl:value-of select="yoj" /></td>
                        <td><xsl:value-of select="email" /></td>
                    </tr>
                </xsl:for-each>
           </table>
       </html>
    </xsl:template>
</xsl:stylesheet>
