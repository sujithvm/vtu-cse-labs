<?xml version="1.0"?>
    <!-- create new namespace instance -->
    <xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
        <!-- match all -->
        <xsl:template match="/">
            <html>
                <!-- create table to display -->
                <table border="1">
                    <tr>
                        <th>USN</th><th>Name</th><th>College</th><th>Branch</th><th>Year Of Joining</th><th>Email-ID</th>
                    </tr>
                    <xsl:for-each select="student/info">
                        <tr>
                            <!-- get each value -->
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
