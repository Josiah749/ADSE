<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html" indent="yes" />
    <xsl:template match="/">
        <html>
            <head>
                <title>Bookstore Inventory Report</title>
                <style>
body { font-family: Arial, sans-serif; margin: 20px; }
table { border-collapse: collapse; width: 70%; }
th, td { border: 1px solid #ccc; padding: 10px; text-align: left; }
th { background-color: #f4f4f4; }
.deal { color: green; font-weight: bold; }
</style>
            </head>
            <body>
                <h2>Bookstore Catalog</h2>
                <table>
                    <tr>
                        <th>ID</th>
                        <th>Title</th>
                        <th>Author</th>
                        <th>Category</th>
                        <th>Year</th>
                        <th>Price</th>
                    </tr>
                    <xsl:for-each select="bookstore/book">
                        <xsl:sort select="title" />
                        <tr>
                            <td>
                                <xsl:value-of select="@id" />
                            </td>
                            <td>
                                <xsl:value-of select="title" />
                            </td>
                            <td>
                                <xsl:value-of select="author" />
                            </td>
                            <td>
                                <xsl:value-of select="@category" />
                            </td>
                            <td>
                                <xsl:value-of select="year" />  
                            </td>
                            <td>
                                <xsl:if test="price &lt; 45">
                                    <xsl:attribute name="class">deal</xsl:attribute>

                                </xsl:if>
                                $<xsl:value-of select="price" />
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>