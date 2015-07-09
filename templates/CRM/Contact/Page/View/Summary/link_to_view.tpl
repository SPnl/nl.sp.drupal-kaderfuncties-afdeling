{capture assign="link_to_view_button"}{strip}
    <li class="crm-odoo-action crm-contact-odoo">
        <a href="{$link_to_view}" class="kaderfuncties-afdeling button" title="{ts}Bekijk/Wijzig afdelingsrelaties{/ts}">
            <span>{ts}Bekijk/Wijzig afdelingsrelaties{/ts}</span>
        </a>
    </li>
{/strip}{/capture}


<script type="text/javascript">
    {literal}
    cj(function() {
        cj('li.crm-summary-block').after('{/literal}{$odoo_button}{literal}');
    });
    {/literal}
</script>